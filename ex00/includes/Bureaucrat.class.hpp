/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:08:01 by bigo              #+#    #+#             */
/*   Updated: 2022/01/07 02:34:53 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP
# include <string>
# include <exception>

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
