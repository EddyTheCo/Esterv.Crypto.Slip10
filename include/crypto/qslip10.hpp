#pragma once

#include<QByteArray>

namespace qcrypto{

	/*! \brief Universal private key derivation from master private key
	 *
	 * Universal private key derivation from master private key for ed25519 curves
	 * Following https://github.com/satoshilabs/slips/blob/master/slip-0010.md
	 *
	 */
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
	/*!
	 *
	 * \brief Master key from seed following https://github.com/satoshilabs/slips/blob/master/slip-0010.md#master-key-generation
	 *
	 * Allows to get extended keys derived from the master key.
	 *
	 */
	class Master_key : public slip10_key_t
	{

		public:
			// Creates a Master key from seed 
			/*!
			 * Creates a Master key from seed byte sequence of 128 to 512 bits in length. This is the same as the seed byte sequence used in BIP-0032

			 */
			Master_key(const QByteArray& seed);
		public:
			// Return derived private keys form path
			slip10_key_t slip10_key_from_path(const QVector<quint32> &path)const;

	};

}
