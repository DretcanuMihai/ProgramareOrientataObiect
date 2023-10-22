#pragma once
#include <QAbstractTableModel>
#include <vector>
using std::vector;
#include "Task.h"
#include <QCheckBox>
#include <set>
using std::set;

class TaskTableModel:public QAbstractTableModel
{
private:
	vector<Task> v;
	vector<QCheckBox*> st;
	set<string> wset;
public:

	//seteaza vectorul de task-uri si de checkbox-uri ale modelului
	void setVector(const vector<Task>& v0,const vector<QCheckBox*>& st0);

	int rowCount(const QModelIndex& p = QModelIndex())const override;
	int columnCount(const QModelIndex& p = QModelIndex())const override;
	QVariant data(const QModelIndex& p, int role = Qt::DisplayRole)const override;
};

