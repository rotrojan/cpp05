/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:43:47 by bigo              #+#    #+#             */
/*   Updated: 2022/01/11 15:31:08 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"
# include <iostream>

static void	check_grade(int sign_grade, int exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int sign_grade, int exec_grade):
	_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false)
{
	check_grade(sign_grade, exec_grade);
	std::cout << "Created: " << *this << std::endl;
}

AForm::AForm(AForm const &form):
	_name(form._name), _sign_grade(form._sign_grade),
	_exec_grade(form._exec_grade), _is_signed(form._is_signed)
{
	check_grade(form._sign_grade, form._exec_grade);
	std::cout << "Copy created: " << *this << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << this->_name << " has been destroyed" << std::endl;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	std::cout << "Assigning " << rhs._name << " signed status to "
		<< this->_name << std::endl;
	if (this != &rhs)
		this->_is_signed = rhs._is_signed;
	return (*this);
}

std::string const	&AForm::get_name(void) const
{
	return (this->_name);
}

int const	&AForm::get_sign_grade(void) const
{
	return (this->_sign_grade);
}

int const	&AForm::get_exec_grade(void) const
{
	return (this->_exec_grade);
}

bool const	&AForm::get_is_signed(void) const
{
	return (this->_is_signed);
}

void	AForm::be_signed(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.get_grade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_is_signed == false)
		throw AForm::NotSignedException();
	do_execute();
	if (this->_exec_grade < executor.get_grade())
		throw AForm::GradeTooLowException();
}

char const	*AForm::NotSignedException::what(void) const throw()
{
	return ("form not signed");
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("form: grade too high");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("form: grade too low");
}

std::ostream	&operator<<(std::ostream &ostream, AForm const &rhs)
{
	std::string	is_signed_str;

	if (rhs.get_is_signed() == true)
		is_signed_str = "signed";
	else
		is_signed_str = "not signed";
	ostream << "form \"" << rhs.get_name()
		<< "\" which is " << is_signed_str
		<< ", requires grade " << rhs.get_sign_grade()
		<< " to be signed and grade " << rhs.get_exec_grade()
		<< " to be executed";
	return (ostream);
}
