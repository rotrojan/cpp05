/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:25:32 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:22:09 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", SIGN_GRADE_ROBOT, EXEC_GRADE_ROBOT), _target(target)
{
	std::cout << "RobotomyRequestForm created for target "
		<< this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form):
	AForm("RobotomyRequestForm", SIGN_GRADE_ROBOT, EXEC_GRADE_ROBOT), _target(form._target)
{
	std::cout << "RobotomyRequestForm copy created for target"
		<< this->_target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void	RobotomyRequestForm::do_execute(void) const
{
	struct timeval seed;
	gettimeofday(&seed, NULL);
	srand(seed.tv_usec);
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "unfortunately, the robotomy of " << this->_target << " is a failure" << std::endl;
}
