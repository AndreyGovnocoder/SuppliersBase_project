#include "Supplier.h"

Supplier::Supplier(int id, const QString& name, bool status, const QString& remark)
	: _id(id)
	, _name(name)
	, _status(status)
	, _remark(remark)
{
}

Supplier::Supplier(const QString& name, bool status, const QString& remark)
	: _id(-1)
	, _name(name)
	, _status(status)
	, _remark(remark)
{
}
