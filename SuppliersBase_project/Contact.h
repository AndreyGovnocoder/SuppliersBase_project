#pragma once
#include <qstring.h>

class Contact
{
public:
    Contact(int id, int supplierId, const QString& name, const QString& phones, const QString& email);
    Contact(int supplierId, const QString& name, const QString& phones, const QString& email);
    Contact() = default;
    ~Contact() = default;

    void set_id(int id) { _id = id; };
    void set_supplierId(int supplierId) { _supplierId = supplierId; };
    void set_name(const QString& name) { _name = name; };
    void set_phones(const QString& phones) { _phones = phones; };
    void set_email(const QString& email) { _email = email; };

    int get_id() const { return _id; };
    int get_supplierId() const { return _supplierId; };
    const QString& get_name() const { return _name; };
    const QString& get_phones() const { return _phones; };
    const QString& get_email() const { return _email; };

private:
    int _id;
    int _supplierId;
    QString _name;
    QString _phones;
    QString _email;
};

