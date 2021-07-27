#pragma once
#include <qstring.h>

class Position
{
public:
	Position(int id, const QString& name, bool active);
	Position(const QString& name, bool active);
	Position() = default;
	~Position() = default;

	void set_id(int id) { _id = id; };
	void set_name(const QString & name) { _name = name; };
	void set_active(bool active) { _active = active; };

	int get_id() const { return _id; };
	const QString& get_name() const { return _name; };
	bool is_active() const { return _active; };

private:
	int _id;
	QString _name;
	bool _active;
};

