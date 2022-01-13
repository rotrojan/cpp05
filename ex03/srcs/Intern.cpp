/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:15:53 by bigo              #+#    #+#             */
/*   Updated: 2022/01/13 16:56:10 by bigo             ###   ########.fr       */
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

// It seems to be realy overkilled to use functions pointers for this where a
// simple switch/case statement would have been both elegant and optimized.
// But the 42's evaluation scale wants an array of function pointers, so ...
// ¯\_(ツ)_/¯

static void	print_form_creation(std::string const &name_form)
{
	std::cout << "Intern creates " << name_form << " form" << std::endl;
}

static AForm	*make_ShrubberyCreationForm(std::string const &form_name, std::string const &form_target)
{
	print_form_creation(form_name);
	return (new ShrubberyCreationForm(form_target));
}

static AForm	*make_RobotomyRequestForm(std::string const &form_name, std::string const &form_target)
{
	print_form_creation(form_name);
	return (new RobotomyRequestForm(form_target));
}

static AForm	*make_PredidentialPardonForm(std::string const &form_name, std::string const &form_target)
{
	print_form_creation(form_name);
	return (new PresidentialPardonForm(form_target));
}

static AForm	*make_null_form(std::string const &form_name, std::string const &form_target)
{
	(void)form_target;
	std::cerr << "Form " << form_name << " not know by the administration." << std::endl;
	return (NULL);
}

AForm	*Intern::make_form(std::string form_name, std::string form_target)
{
	int i = 0;
	std::string known_form[NB_KNOWN_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm	*(*form_ptr[NB_KNOWN_FORMS + 1])(std::string const &, std::string const &) = {
		&make_ShrubberyCreationForm,
		&make_RobotomyRequestForm,
		&make_PredidentialPardonForm,
		&make_null_form
	};

	while (i < NB_KNOWN_FORMS && form_name != known_form[i])
		++i;
	return (form_ptr[i](form_name, form_target));
}
