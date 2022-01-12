/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:25:32 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:27:08 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sys/time.h>

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", SIGN_GRADE_PARDON, EXEC_GRADE_PARDON), _target(target)
{
	std::cout << "PresidentialPardonForm created for target "
		<< this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form):
	AForm("PresidentialPardonForm", SIGN_GRADE_PARDON, EXEC_GRADE_PARDON), _target(form._target)
{
	std::cout << "PresidentialPardonForm copy created for target"
		<< this->_target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void	PresidentialPardonForm::do_execute(void) const
{
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
			<< std::endl;
}
