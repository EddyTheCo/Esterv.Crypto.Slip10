#include "esterv/crypto/ed25519.hpp"
#include "esterv/crypto/slip10.hpp"
#include <iostream>
#undef NDEBUG
#include <QVector>
#include <assert.h>

using namespace Esterv::Crypto;

int main(int argc, char **argv)
{
    // TEST 1
    auto seed = QByteArray::fromHex("000102030405060708090a0b0c0d0e0f");
    QVector<quint32> path = {0, 1, 2, 2, 1000000000};
    auto MK = Master_key(seed);
    auto keys = MK.slip10_key_from_path(path);

    assert(keys.chain_code() ==
           QByteArray::fromHex("68789923a0cac2cd5a29172a475fe9e0fb14cd6adb5ad98a3fa70333e7afa230"));

    auto edkeys = Ed25519::create_keypair(keys.secret_key());
    assert(keys.secret_key() ==
           QByteArray::fromHex("8f94d394a8e8fd6b1bc2f3f49f5c47e385281d5c17e65324b0f62483e37e8793"));
    assert(edkeys.first == QByteArray::fromHex("3c24da049451555d51a7014a37337aa4e12d41e485abccfa46b47dfb2af54b7a"));

    // TEST 2
    seed = QByteArray::fromHex("fffcf9f6f3f0edeae7e4e1dedbd8d5d2cfccc9c6c3c0bdbab7b4b1aeaba8a5a29f9c999693908d8a8784817"
                               "e7b7875726f6c696663605d5a5754514e4b484542");
    path = {0, 2147483647, 1, 2147483646, 2};
    MK = Master_key(seed);
    keys = MK.slip10_key_from_path(path);

    assert(keys.chain_code() ==
           QByteArray::fromHex("5d70af781f3a37b829f0d060924d5e960bdc02e85423494afc0b1a41bbe196d4"));

    edkeys = Ed25519::create_keypair(keys.secret_key());
    assert(keys.secret_key() ==
           QByteArray::fromHex("551d333177df541ad876a60ea71f00447931c0a9da16f227c11ea080d7391b8d"));
    assert(edkeys.first == QByteArray::fromHex("47150c75db263559a70d5778bf36abbab30fb061ad69f69ece61a72b0cfa4fc0"));

    return 0;
}
