/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2004 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DESKFLOW_LIB_IO_FILESYSTEM_H
#define DESKFLOW_LIB_IO_FILESYSTEM_H

#include <cstdio>
#include <ghc/fs_fwd.hpp>
#include <ios>
#include <iosfwd>

namespace deskflow {

namespace fs = ghc::filesystem;

void open_utf8_path(std::ifstream &stream, const fs::path &path, std::ios_base::openmode mode = std::ios_base::in);
void open_utf8_path(std::ofstream &stream, const fs::path &path, std::ios_base::openmode mode = std::ios_base::out);
void open_utf8_path(
    std::fstream &stream, const fs::path &path, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out
);

std::FILE *fopen_utf8_path(const fs::path &path, const std::string &mode);

} // namespace deskflow

#endif // DESKFLOW_LIB_IO_FILESYSTEM_H
