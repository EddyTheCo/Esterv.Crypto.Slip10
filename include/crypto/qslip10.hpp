#pragma once
/**
 *  https://github.com/satoshilabs/slips/blob/master/slip-0010.md
 *
 **/

#include<QByteArray>
#include<QDebug>
namespace qcrypto{

class slip10_key_t : public QByteArray
{

    using QByteArray::QByteArray;
public:
    QByteArray secret_key(void)const{
        return QByteArray(data(),32) ;
    };
    QByteArray chain_code(void)const{
        return QByteArray(data()+32,32) ;
    };


};
class Master_key : public slip10_key_t
{

public:
    Master_key(const QByteArray& seed);
public:
    slip10_key_t slip10_key_from_path(const QVector<quint32> &path)const;

};

}
