/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/18 14:04:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.class.hpp"

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
		bur_ptr->decrement_grade();
		std::cout << *bur_ptr << std::endl;
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot decrement bureaucrat's grade: " << except.what() << std::endl;
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
		bur_ptr->increment_grade();
		std::cout << *bur_ptr << std::endl;
	}
	catch (std::exception const &except)
	{
		std::cerr << "Cannot increment bureaucrat's grade: " << except.what() << std::endl;
	}
	delete bur_ptr;
	std::cout << std::endl;
}

int	main(void)
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

	return (EXIT_SUCCESS);
}
