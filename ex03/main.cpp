/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 04:10:58 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "Intern.class.hpp"

int	main(void)
{
	Bureaucrat zap1("Zap1", 1);
	Intern intern;
	AForm *form;
	std::cout << std::endl;
	{
		form = intern.make_form("shrubbery creation", "Planet2000Express");
		zap1.execute_form(*form);
		zap1.sign_form(*form);
		zap1.execute_form(*form);
		delete form;
	}
		std::cout << std::endl;
	{
		form = intern.make_form("robotomy request", "Fry");
		zap1.execute_form(*form);
		zap1.sign_form(*form);
		zap1.execute_form(*form);
		delete form;
	}
		std::cout << std::endl;
	{
		form = intern.make_form("presidential pardon", "Bender");
		zap1.execute_form(*form);
		zap1.sign_form(*form);
		zap1.execute_form(*form);
		delete form;
	}
	std::cout << std::endl;
	{
		form = intern.make_form("unacceptable delivery", "Zoidberg");
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
