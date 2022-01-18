/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:08:01 by bigo              #+#    #+#             */
/*   Updated: 2022/01/18 14:02:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.class.hpp"

static void	check_grade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	check_grade(this->_grade);
	std::cout << "Bureaucrat " << this->_name << ", grade " << this->_grade
		<< " has been hired" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat): _name(bureaucrat._name), _grade(bureaucrat._grade)
{
	check_grade(this->_grade);
	std::cout << "Bureaucrat's copy " << this->_name << ", grade " << this->_grade
		<< " has been hired" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->_name << " has been fired" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Assigning " << rhs._name << "'s grade to " << this->_name << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::string const	Bureaucrat::get_name(void) const
{
	return (this->_name);
}

int	Bureaucrat::get_grade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::decrement_grade(void)
{
	std::cout << "Decrementing " << this->_name << "'s grade" << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		++this->_grade;
}

void	Bureaucrat::increment_grade(void)
{
	std::cout << "Incrementing " << this->_name << "'s grade" << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--this->_grade;
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("bureaucrat's grade cannot be above 1");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("bureaucrat's grade cannot be under 150");
}

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &rhs)
{
	ostream << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
	return (ostream);
}
