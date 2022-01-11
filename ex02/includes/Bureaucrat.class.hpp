/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:08:01 by bigo              #+#    #+#             */
/*   Updated: 2022/01/11 15:13:36 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP
# include <string>
# include <exception>
# include "AForm.class.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name = "Bureaucrat", int grade = 150);
		Bureaucrat(Bureaucrat const &bureaucrat);
		virtual ~Bureaucrat(void);
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		std::string const	get_name(void) const;
		int					get_grade(void) const;
		void				increment_grade(void);
		void				decrement_grade(void);
		void				sign_form(AForm &form) const;
		void				execute_form(AForm const &form) const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &rhs);

#endif
