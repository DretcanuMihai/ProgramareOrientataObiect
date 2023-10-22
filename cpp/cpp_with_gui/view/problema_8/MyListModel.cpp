#include "MyListModel.h"

MyListModel::MyListModel(QObject* parent0):QAbstractListModel(parent0)
{
}

void MyListModel::setVec(const vector<Locatar>& v0)
{
	v = v0;
	QModelIndex start=createIndex(0,0);
	QModelIndex finish=createIndex(rowCount(),0);
	emit dataChanged(start,finish);
}

int MyListModel::rowCount(const QModelIndex& parent) const
{
	return v.size();
}

QVariant MyListModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole) {
		int r = index.row();
		return QString::number(v.at(r).get_apartament());
	}
	return QVariant();
}
