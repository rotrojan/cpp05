/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:49 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:04:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP
# include <string>
# include <AForm.class.hpp>
# define SIGN_GRADE_SHRUB 145
# define EXEC_GRADE_SHRUB 137

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target = "default");
		ShrubberyCreationForm(ShrubberyCreationForm const &form);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		void					do_execute(void) const;
	private:
		std::string const		_target;
};

#endif
