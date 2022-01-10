/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:49 by bigo              #+#    #+#             */
/*   Updated: 2022/01/10 19:35:50 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <exception>
# include <Bureaucrat.class.hpp>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name = "form", int sign_grade = 1, int exec_grade = 1);
		Form(Form const &form);
		virtual ~Form(void);
		Form				&operator=(Form const &rhs);
		std::string const	&get_name(void) const;
		int const			&get_sign_grade(void) const;
		int const			&get_exec_grade(void) const;
		bool const			&get_is_signed(void) const;
		void				be_signed(Bureaucrat const &bureaucrat);
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
		int const			_sign_grade;
		int const			_exec_grade;
		bool				_is_signed;
};

std::ostream	&operator<<(std::ostream &ostream, Form const &rhs);

#endif
