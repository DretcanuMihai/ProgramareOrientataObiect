#pragma once
#include <QAbstractTableModel>
#include <unordered_map>
using std::unordered_map;
#include <string>
using std::string;
using std::pair;
#include <vector>
using std::vector;

class MyTableModel:public QAbstractTableModel
{
private:
	vector<pair<string, int>> v;
public:
	MyTableModel(QObject* parent);
	void setVec(const unordered_map<string, int>& v0);
	int rowCount(const QModelIndex& parent = QModelIndex())const override;
	int columnCount(const QModelIndex& parent = QModelIndex())const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;

};

