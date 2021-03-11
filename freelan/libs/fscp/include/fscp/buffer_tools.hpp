/*
 * libfscp - A C++ library to establish peer-to-peer virtual private networks.
 * Copyright (C) 2010-2011 Julien Kauffmann <julien.kauffmann@freelan.org>
 *
 * This file is part of libfscp.
 *
 * libfscp is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libfscp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libfscp in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file buffer_tools.hpp
 * \author Julien Kauffmann <julien.kauffmann@freelan.org>
 * \brief Buffer manipulation tools.
 */

#ifndef FSCP_BUFFER_TOOLS_HPP
#define FSCP_BUFFER_TOOLS_HPP

#include <cstring>
#include <stdint.h>

namespace fscp
{
	namespace buffer_tools
	{
		/**
		 * \brief Get a value from a buffer.
		 * \param buf The buffer.
		 * \param offset The offset of the value to read.
		 */
		template <typename Type>
		Type get(const void* buf, size_t offset);

		/**
		 * \brief Set a value in a buffer.
		 * \param buf The buffer.
		 * \param offset The offset of the value to write.
		 * \param value The value to write.
		 */
		template <typename Type>
		void set(void* buf, size_t offset, Type value);

		/**
		 * \brief Get a value from a buffer.
		 * \param buf The buffer.
		 * \param offset The offset of the value to read.
		 */
		uint8_t get(const void* buf, size_t offset);

		/**
		 * \brief Set a value in a buffer.
		 * \param buf The buffer.
		 * \param offset The offset of the value to write.
		 * \param value The value to write.
		 */
		void set(void* buf, size_t offset, uint8_t value);

		template <typename Type>
		inline Type get(const void* buf, size_t offset)
		{
			return *reinterpret_cast<const Type*>(static_cast<const uint8_t*>(buf) + offset);
		}

		template <typename Type>
		inline void set(void* buf, size_t offset, Type value)
		{
			*reinterpret_cast<Type*>(static_cast<uint8_t*>(buf) + offset) = value;
		}

		inline uint8_t get(const void* buf, size_t offset)
		{
			return static_cast<const uint8_t*>(buf)[offset];
		}

		inline void set(void* buf, size_t offset, uint8_t value)
		{
			static_cast<uint8_t*>(buf)[offset] = value;
		}
	}
}

#endif /* FSCP_BUFFER_TOOLS_HPP */