/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/11 15:23:13 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

int	main(void)
{
	Bureaucrat bob("Bob", 50);
	Bureaucrat tod("Tod", 150);
	ShrubberyCreationForm scf("garden");
	tod.execute_form(scf);
	bob.execute_form(scf);
	tod.sign_form(scf);
	bob.sign_form(scf);
	tod.execute_form(scf);
	bob.execute_form(scf);
	return (EXIT_SUCCESS);
}
