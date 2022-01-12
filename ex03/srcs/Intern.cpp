/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:15:53 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 03:53:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"


Intern::Intern(void)
{
	std::cout << "Intern hired" << std::endl;
}

Intern::Intern(Intern const &intern)
{
	(void)intern;
	std::cout << "Intern copy hired" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern fired" << std::endl;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::make_form(std::string form_name, std::string form_target)
{
	int i = 0;
	std::string known_form[NB_KNOWN_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	while (i < NB_KNOWN_FORMS && form_name != known_form[i])
		++i;
	if (i < NB_KNOWN_FORMS)
		std::cout << "Intern creates " << known_form[i] << " form" << std::endl;
	else
		std::cerr << "Form " << form_name << " not know by the administration."
			<< std::endl;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(form_target));
		case 1:
			return (new RobotomyRequestForm(form_target));
		case 2:
			return (new PresidentialPardonForm(form_target));
		default:
			return (NULL);
	}
}
