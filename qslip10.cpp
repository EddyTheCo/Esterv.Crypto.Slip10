#include"crypto/qslip10.hpp"
#include<QIODevice>
#include <QMessageAuthenticationCode>
namespace qcrypto{
#define BIP32_HARDENED (1UL << 31)

	/*
	 * The function CKDpriv((kpar, cpar), i) → (ki, ci) computes a child extended private key from the parent extended private key
	 *
	 */
	slip10_key_t private_ckd(const slip10_key_t& key, quint32 index) {
		QByteArray data;
		data.push_front('\x00');
		QDataStream BigIndianStream(&data, QIODevice::WriteOnly|QIODevice::Append);
		BigIndianStream.setByteOrder(QDataStream::BigEndian);
		BigIndianStream.writeRawData(key.secret_key(),key.secret_key().size());
		BigIndianStream<<index;
		const auto hmac=QMessageAuthenticationCode::hash(data, key.chain_code(), QCryptographicHash::Sha512);
		return slip10_key_t(hmac.constData(),hmac.size());
	}

	slip10_key_t Master_key::slip10_key_from_path(const QVector<quint32>& path)const {

		auto masterKey=static_cast<slip10_key_t>(*this);
		for (int i = 0; i < path.size(); i++) {
			masterKey=private_ckd(masterKey,path.at(i)|BIP32_HARDENED);
		}
		return masterKey;

	}

	Master_key::Master_key(const QByteArray& seed):
		slip10_key_t(QMessageAuthenticationCode::hash(seed, QByteArray("ed25519 seed"), QCryptographicHash::Sha512).constData(),64)
	{
	}

}
