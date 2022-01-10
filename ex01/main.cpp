/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/10 21:55:59 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

static void test(std::string const &name, int grade)
{
	Bureaucrat	*bur_ptr = NULL;

	try
	{
		bur_ptr = new Bureaucrat(name, grade);
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot create bureaucrat: " << except.what() << std::endl;
		return ;
	}
	try
	{
		bur_ptr->increment_grade();
		std::cout << *bur_ptr << std::endl;
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot increment bureaucrat's grade: " << except.what() << std::endl;
	}
	try
	{
		bur_ptr->decrement_grade();
		std::cout << *bur_ptr << std::endl;
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot decrement bureaucrat's grade: " << except.what() << std::endl;
	}
	delete bur_ptr;
	std::cout << std::endl;
}

static void	form_test(std::string &name, int sign_grade, int exec_grade)
{
	Form	*form_ptr = NULL;

	std::cout << "Form \"" << name << "\", sign_grade " << sign_grade
		<< ", exec_grade " << exec_grade << std::endl;
	try
	{
		form_ptr = new Form(name, sign_grade, exec_grade);
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot create form: " << except.what() << std::endl;
	}
	delete form_ptr;
	std::cout << std::endl;
}

int	main(void)
{
	{
		test("Bob", 12);
		test("Ted", 151);
		test("Tod", 150);
		test("Don", 0);
		test("Dan", 1);

		Bureaucrat yan("Yan", 42);
		Bureaucrat yan_bis(yan);
		Bureaucrat yon("Yon", 21);
		yon = yan;
		std::cout << yon << std::endl;
	}

	std::cout << std::endl << "#################################" << std::endl << std::endl;

	{
		std::string str = "licence";
		form_test(str, 1, 0);
		form_test(str, 0, 1);
		form_test(str, 0, 0);
		form_test(str, 150, 151);
		form_test(str, 151, 150);
		form_test(str, 151, 151);

		Bureaucrat	bob("Bob", 42);
		Bureaucrat	tod("Tod", 80);
		Form		licence1("licence1", 50, 60);
		tod.sign_form(licence1);
		std::cout << licence1 << std::endl;
		bob.sign_form(licence1);
		std::cout << licence1 << std::endl;
		std::cout << std::endl;

		Form licence2(licence1);
		std::cout << licence2 << std::endl;
		Form licence3(str, 42, 42);
		licence3 = licence2;
		std::cout << licence3 << std::endl;
	}
	return (EXIT_SUCCESS);
}
