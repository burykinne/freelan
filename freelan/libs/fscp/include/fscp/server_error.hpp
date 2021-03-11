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
 * \file server_error.hpp
 * \author Julien Kauffmann <julien.kauffmann@freelan.org>
 * \brief The server errors.
 */

#ifndef FSCP_SERVER_ERROR_HPP
#define FSCP_SERVER_ERROR_HPP

#include <boost/system/error_code.hpp>
#include <boost/type_traits/integral_constant.hpp>

#include <string>

namespace fscp
{
	/**
	 * @brief Get the default server error category.
	 * @return The default server error category instance.
	 *
	 * @warning The first call to this function is thread-safe only starting with C++11.
	 */
	const boost::system::error_category& server_category();

	namespace server_error
	{
		/**
		 * The list of server errors.
		 */
		enum server_error_t
		{
			success = 0,
			server_offline,
			hello_request_timed_out,
			no_presentation_for_host,
			session_already_exist,
			no_session_for_host
		};

		/**
		 * @brief Create an error_code instance for the given error.
		 * @param error The error.
		 * @return The error_code instance.
		 */
		inline boost::system::error_code make_error_code(server_error_t error)
		{
			return boost::system::error_code(static_cast<int>(error), server_category());
		}

		/**
		 * @brief Create an error_condition instance for the given error.
		 * @param error The error.
		 * @return The error_condition instance.
		 */
		inline boost::system::error_condition make_error_condition(server_error_t error)
		{
			return boost::system::error_condition(static_cast<int>(error), server_category());
		}
	}

	/**
	 * @brief A server error category.
	 */
	class server_category_impl : public boost::system::error_category
	{
		public:
			/**
			 * @brief Get the name of the category.
			 * @return The name of the category.
			 */
			virtual const char* name() const throw();

			/**
			 * @brief Get the error message for a given error.
			 * @param ev The error numeric value.
			 * @return The message associated to the error.
			 */
			virtual std::string message(int ev) const;
	};
}

namespace boost
{
	namespace system
	{
		template <>
		struct is_error_code_enum< ::fscp::server_error::server_error_t> : public boost::true_type {};
	}
}

#endif /* FSCP_SERVER_ERROR_HPP */