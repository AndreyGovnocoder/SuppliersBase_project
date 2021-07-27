#include "Position.h"

Position::Position(int id, const QString& name, bool active)
	: _id(id)
	, _name(name)
	, _active(active)
{
}

Position::Position( const QString& name, bool active)
	: _id(-1)
	, _name(name)
	, _active(active)
{
}
