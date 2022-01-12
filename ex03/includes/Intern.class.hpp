/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:15:53 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 03:53:44 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP
# include <string>
# include "AForm.class.hpp"
# define NB_KNOWN_FORMS 3

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &intern);
		virtual ~Intern(void);
		Intern	&operator=(Intern const &rhs);
		AForm	*make_form(std::string form_name, std::string form_target);
};

#endif
