/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:25:32 by bigo              #+#    #+#             */
/*   Updated: 2022/01/11 15:41:33 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm created for target "
		<< this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form):
	AForm("ShrubberyCreationForm", 145, 137), _target(form._target)
{
	std::cout << "ShrubberyCreationForm copy created for target"
		<< this->_target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void	ShrubberyCreationForm::do_execute(void) const
{
	std::string file_name = this->_target + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (file.fail() == true)
		std::cerr << "Error: cannot create file" << std::endl;
	else
	{
		file << "                                              ." << std::endl;
		file << "                                   .         ;" << std::endl;
		file << "      .              .              ;%     ;;" << std::endl;
		file << "        ,           ,                :;%  %;" << std::endl;
		file << "         :         ;                   :;%;'     .," << std::endl;
		file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
		file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
		file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
		file << "           `@%:.  :;%.         ;@@%;'" << std::endl;
		file << "             `@%.  `;@%.      ;@@%;" << std::endl;
		file << "               `@%%. `@%%    ;@@%;" << std::endl;
		file << "                 ;@%. :@%%  %@@%;" << std::endl;
		file << "                   %@bd%%%bd%%:;" << std::endl;
		file << "                     #@%%%%%:;;" << std::endl;
		file << "                     %@@%%%::;" << std::endl;
		file << "                     %@@@%(o);  . '" << std::endl;
		file << "                     %@@@o%;:(.,'" << std::endl;
		file << "                 `.. %@@@o%::;" << std::endl;
		file << "                    `)@@@o%::;" << std::endl;
		file << "                     %@@(o)::;" << std::endl;
		file << "                    .%@@@@%::;" << std::endl;
		file << "                    ;%@@@@%::;." << std::endl;
		file << "                   ;%@@@@%%:;;;." << std::endl;
		file << "               ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;
		file.close();
	}
}
