#include "Contact.h"

Contact::Contact(int id, int supplierId, const QString& name, const QString& phones, const QString& email)
	: _id(id)
	, _supplierId(supplierId)
	, _name(name)
	, _phones(phones)
	, _email(email)
{
}

Contact::Contact(int supplierId, const QString& name, const QString& phones, const QString& email)
	: _supplierId(supplierId)
	, _name(name)
	, _phones(phones)
	, _email(email)
{
}

