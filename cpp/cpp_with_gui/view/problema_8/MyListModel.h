#pragma once

#include <QAbstractListModel>
#include "Locatar.h"
#include <vector>
using std::vector;

class MyListModel:public QAbstractListModel
{
private:
	vector<Locatar> v;
public:
	MyListModel(QObject* parent0);
	void setVec(const vector<Locatar>& v0);
	int rowCount(const QModelIndex& parent=QModelIndex())const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;

};

