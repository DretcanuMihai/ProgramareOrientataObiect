#include "MyTableModel.h"


MyTableModel::MyTableModel(QObject* parent):QAbstractTableModel(parent)
{
}

void MyTableModel::setVec(const unordered_map<string, int>& v0)
{
	beginResetModel();
	vector<pair<string, int>> vf;
	for (const auto& elem : v0) {
		vf.push_back(elem);
	}
	v = vf;
	QModelIndex st = createIndex(0, 0);
	QModelIndex fin = createIndex(rowCount(), columnCount());
	emit dataChanged(st, fin);
	endResetModel();
}

int MyTableModel::rowCount(const QModelIndex& parent) const
{
	return v.size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
	return 2;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole) {
		const auto& l = v.at(index.row());
		if (index.column() == 0)
			return QString::fromStdString(l.first);
		else
			return QString::number(l.second);
	}
	return QVariant();
}
