#include "ServiciuTask.h"

ServiciuTask::ServiciuTask(ValidatorTask& val0, RepoTask& repo0):val{val0},repo{repo0}
{
}

void ServiciuTask::adauga(int id, const string& descriere, const list<string>& prog, const string& stare)
{
	Task t{ id,descriere,prog,stare };
	val.valideaza(t);
	repo.adauga(t);
}

void ServiciuTask::stergePg(const string& nume)
{
	vector<int> to_del;
	for (const auto& elem : repo.getAll()) {
		for (const auto& el : elem.getProgramatori()) {
			if (el == nume) {
				to_del.push_back(elem.getId());
				break;
			}
		}
	}
	for (auto id : to_del) {
		repo.sterge(id);
	}
}

const vector<Task>& ServiciuTask::getAll() const
{
	return repo.getAll();
}
