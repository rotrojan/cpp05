/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:49 by bigo              #+#    #+#             */
/*   Updated: 2022/01/12 02:04:07 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP
# include <string>
# include <AForm.class.hpp>
# define SIGN_GRADE_ROBOT 72
# define EXEC_GRADE_ROBOT 45

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target = "default");
		RobotomyRequestForm(RobotomyRequestForm const &form);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		void					do_execute(void) const;
	private:
		std::string const		_target;
};

#endif
