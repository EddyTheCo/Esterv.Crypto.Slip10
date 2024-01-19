# Universal private key derivation from master private key 

This repo produce a library for deriving private keys from a master key following this [slip](https://github.com/satoshilabs/slips/blob/master/slip-0010.md).
This repo only works with ed25519 curve types.


## API reference

You can read the [API reference](https://eddytheco.github.io/Qslip10/) here, or generate it yourself like
```
cmake -DBUILD_DOCS=ON ../
cmake --build . --target doxygen_docs
```

## Contributing

We appreciate any contribution!


You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.
