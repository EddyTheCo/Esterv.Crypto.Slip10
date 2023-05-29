# Universal private key derivation from master private key 

Implements a Simple library for generating pair keys from a master key following this [slip](https://github.com/satoshilabs/slips/blob/master/slip-0010.md).
This repo only works with ed25519 curve types.


## API reference

You can read the [API reference](https://eddytheco.github.io/Qslip10/) here, or generate it yourself like
```
cmake -DBUILD_DOCS=ON ../
cmake --build . --target doxygen_docs
```
