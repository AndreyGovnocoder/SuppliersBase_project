#pragma once
#include <qstring.h>
#include <vector>

class Supplier
{
public:
	Supplier(int id, const QString& name, bool status, const QString& remark);
	Supplier(const QString& name, bool status, const QString& remark);
	Supplier() = default;
	~Supplier() = default;

	void set_id(int id) { _id = id; };
	void set_name(const QString& name) { _name = name; };
	void set_status(bool status) { _status = status; };
	void set_remark(const QString& remark) { _remark = remark; };
	void add_position(int positionId) { _positions.push_back(std::move(positionId)); };

	int get_id() const { return _id; };
	const QString& get_name() const { return _name; };
	bool is_status() const { return _status; };
	const QString& get_remark() const { return _remark; };
	const std::vector<int>& get_positions() const { return _positions; };
	void clearPositions() { _positions.clear(); };
	
private:
	int _id;
	QString _name;
	bool _status;
	QString _remark;
	std::vector<int> _positions;
};

