/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:34:37 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int	main(void)
{
	Bureaucrat zap1("Zap1", 1);
	Bureaucrat bob20("Bob20", 20);
	Bureaucrat dan70("Dan70", 70);
	Bureaucrat ted100("Ted100", 100);
	Bureaucrat tod150("Tod150", 150);
	std::cout << std::endl;
	{
		ShrubberyCreationForm scf("Planet2000Express");
		tod150.execute_form(scf);
		ted100.execute_form(scf);
		tod150.sign_form(scf);
		ted100.sign_form(scf);
		tod150.execute_form(scf);
		ted100.execute_form(scf);
	}
		std::cout << std::endl;
	{
		RobotomyRequestForm rrf("Fry");
		ted100.execute_form(rrf);
		dan70.execute_form(rrf);
		ted100.sign_form(rrf);
		dan70.sign_form(rrf);
		dan70.execute_form(rrf);
		bob20.execute_form(rrf);
		bob20.execute_form(rrf);
		bob20.execute_form(rrf);
		bob20.execute_form(rrf);
		bob20.execute_form(rrf);
	}
		std::cout << std::endl;
	{
		PresidentialPardonForm ppf("Bender");
		bob20.execute_form(ppf);
		zap1.execute_form(ppf);
		dan70.sign_form(ppf);
		bob20.sign_form(ppf);
		bob20.execute_form(ppf);
		zap1.execute_form(ppf);
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
