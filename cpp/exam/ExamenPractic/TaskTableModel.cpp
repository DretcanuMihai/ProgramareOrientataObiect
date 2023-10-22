#include "TaskTableModel.h"
#include <QBrush>

void TaskTableModel::setVector(const vector<Task>& v0, const vector<QCheckBox*>& st0)
{
    beginResetModel();
    v = v0;
    st = st0;
    wset.clear();
    for (const auto& elem : st) {
        if (elem->isChecked()) {
            wset.insert(elem->text().toStdString());
        }
    }
    QModelIndex start = createIndex(0, 0);
    QModelIndex finish = createIndex(v.size(), 4);
    emit dataChanged(start, finish);
    endResetModel();
}

int TaskTableModel::rowCount(const QModelIndex& p) const
{
    return v.size();
}

int TaskTableModel::columnCount(const QModelIndex& p) const
{
    return 4;
}

QVariant TaskTableModel::data(const QModelIndex& p, int role) const
{
    auto r=p.row();
    auto c = p.column();
    if (role == Qt::DisplayRole) {
        auto t = v.at(r);
        if (c == 0) {
            return QString::number(t.getId());
        }
        if (c == 1) {
            return QString::fromStdString(t.getDescriere());
        }
        if (c == 2) {
            auto lista_mea = t.getProgramatori();
            string to_show;
            for (auto it = lista_mea.begin(); it != lista_mea.end(); ++it) {
                if (it != lista_mea.begin()) {
                    to_show += ",";
                }
                to_show += *it;
            }
            return QString::fromStdString(to_show);
        }
        if (c == 3) {
            return QString::fromStdString(t.getStare());
        }
    }
    if (role == Qt::BackgroundRole) {
        auto t = v.at(r);
        bool ok = false;
        for (const auto& elem : t.getProgramatori()) {
            if (wset.find(elem) != wset.end()) {
                return QBrush{ Qt::red };
            }
        }
    }
    return QVariant();
}
