/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:43:47 by bigo              #+#    #+#             */
/*   Updated: 2022/01/10 22:01:55 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"
# include <iostream>

static void	check_grade(int sign_grade, int exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int sign_grade, int exec_grade):
	_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false)
{
	check_grade(sign_grade, exec_grade);
	std::cout << "Created: " << *this << std::endl;
}

Form::Form(Form const &form):
	_name(form._name), _sign_grade(form._sign_grade),
	_exec_grade(form._exec_grade), _is_signed(form._is_signed)
{
	check_grade(form._sign_grade, form._exec_grade);
	std::cout << "Copy created: " << *this << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	std::cout << "Assigning " << rhs._name << " signed status to "
		<< this->_name << std::endl;
	if (this != &rhs)
		this->_is_signed = rhs._is_signed;
	return (*this);
}

std::string const	&Form::get_name(void) const
{
	return (this->_name);
}

int const	&Form::get_sign_grade(void) const
{
	return (this->_sign_grade);
}

int const	&Form::get_exec_grade(void) const
{
	return (this->_exec_grade);
}

bool const	&Form::get_is_signed(void) const
{
	return (this->_is_signed);
}

void	Form::be_signed(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.get_grade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("grade of form too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade of form too low");
}

std::ostream	&operator<<(std::ostream &ostream, Form const &rhs)
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
