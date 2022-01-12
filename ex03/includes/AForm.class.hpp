/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:49 by bigo              #+#    #+#             */
/*   Updated: 2022/01/11 14:40:31 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <exception>
# include <Bureaucrat.class.hpp>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name = "form", int sign_grade = 1, int exec_grade = 1);
		AForm(AForm const &form);
		virtual ~AForm(void);
		AForm				&operator=(AForm const &rhs);
		std::string const	&get_name(void) const;
		int const			&get_sign_grade(void) const;
		int const			&get_exec_grade(void) const;
		bool const			&get_is_signed(void) const;
		void				be_signed(Bureaucrat const &bureaucrat);
		virtual void		do_execute(void) const = 0;
		void				execute(Bureaucrat const &executor) const;
		class NotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
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

std::ostream	&operator<<(std::ostream &ostream, AForm const &rhs);

#endif
