# MIT License
#
# Copyright (c) 2022 Uriel Rivas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# https://github.com/zoningorg/zoning/blob/main/LICENSE

all: data test clean

data:
	cd DataStructures && make

# TODO(Garz4): Enable arguments to only test certain parts,
#   e. g., "make test DataStructures FileTransfer"
test: DataStructuresTest FileTransferTest

DataStructuresTest:
	cd DataStructures && make test

FileTransferTest:
	cd FileTransfer && make test

clean:
	whoami
