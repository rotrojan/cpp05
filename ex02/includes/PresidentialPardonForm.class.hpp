/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:49 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:26:09 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP
# include <string>
# include <AForm.class.hpp>
# define SIGN_GRADE_PARDON 25
# define EXEC_GRADE_PARDON 5

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(std::string target = "default");
		PresidentialPardonForm(PresidentialPardonForm const &form);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		void					do_execute(void) const;
	private:
		std::string const		_target;
};

#endif
