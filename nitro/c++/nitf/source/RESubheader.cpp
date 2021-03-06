/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2010, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include "nitf/RESubheader.hpp"

using namespace nitf;

RESubheader::RESubheader(const RESubheader & x)
{
    setNative(x.getNative());
}

RESubheader & RESubheader::operator=(const RESubheader & x)
{
    if (&x != this)
        setNative(x.getNative());
    return *this;
}

RESubheader::RESubheader(nitf_RESubheader * x)
{
    setNative(x);
    getNativeOrThrow();
}

RESubheader::RESubheader() throw(nitf::NITFException)
{
    setNative(nitf_RESubheader_construct(&error));
    getNativeOrThrow();
    setManaged(false);
}


nitf::RESubheader RESubheader::clone() throw(nitf::NITFException)
{
    nitf::RESubheader dolly(
        nitf_RESubheader_clone(getNativeOrThrow(), &error));
    dolly.setManaged(false);
    return dolly;
}

RESubheader::~RESubheader(){}


nitf::Field RESubheader::getFilePartType()
{
    return nitf::Field(getNativeOrThrow()->filePartType);
}

nitf::Field RESubheader::getTypeID()
{
    return nitf::Field(getNativeOrThrow()->typeID);
}

nitf::Field RESubheader::getVersion()
{
    return nitf::Field(getNativeOrThrow()->version);
}

nitf::Field RESubheader::getSecurityClass()
{
    return nitf::Field(getNativeOrThrow()->securityClass);
}

nitf::FileSecurity RESubheader::getSecurityGroup()
{
    return nitf::FileSecurity(getNativeOrThrow()->securityGroup);
}

void RESubheader::setSecurityGroup(nitf::FileSecurity value)
{
    //release the owned security group
    nitf::FileSecurity fs = nitf::FileSecurity(getNativeOrThrow()->securityGroup);
    fs.setManaged(false);

    //have the library manage the new securitygroup
    getNativeOrThrow()->securityGroup = value.getNative();
    value.setManaged(true);
}

nitf::Field RESubheader::getSubheaderFieldsLength()
{
    return nitf::Field(getNativeOrThrow()->subheaderFieldsLength);
}

char * RESubheader::getSubheaderFields() const
{
    return getNativeOrThrow()->subheaderFields;
}

nitf::Uint64 RESubheader::getDataLength() const
{
    return getNativeOrThrow()->dataLength;
}

void RESubheader::setDataLength(nitf::Uint32 value)
{
    getNativeOrThrow()->dataLength = value;
}
