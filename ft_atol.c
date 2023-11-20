/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:47:58 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 18:19:01 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int chr);
static int	ft_isdigit(int chr);
static int	check_sign(const char **from_ascii, int sign);
static int	check_flows(unsigned long long digit2p, \
	unsigned long long digit1, int sign);

long	ft_atol(const char *from_ascii)
{
	int					sign;
	unsigned long long	to_long;
	unsigned long long	digit1;

	if (from_ascii == NULL)
		return (LONG_MAX);
	while (ft_isspace(*from_ascii))
		from_ascii += 1;
	sign = check_sign(&from_ascii, 0);
	if (!ft_isdigit(*from_ascii))
		return (LONG_MAX);
	to_long = 0;
	digit1 = 0;
	while (*from_ascii)
	{
		if (!ft_isdigit(*from_ascii))
			return (LONG_MAX);
		digit1 = *from_ascii - '0';
		if (check_flows(to_long, digit1, sign) == ERROR)
			return (LONG_MAX);
		to_long = (to_long * 10) + digit1;
		from_ascii += 1;
	}
	return ((long)to_long * sign);
}
		// if (check_flows(to_long, digit1, sign) == UNDERFLOW)
		// 	return (LONG_MIN);

static int	ft_isspace(int chr)
{
	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
}

static int	ft_isdigit(int chr)
{
	return (chr >= '0' && chr <= '9');
}

static int	check_sign(const char **from_ascii, int sign)
{
	sign = POSITIVE;
	if (**from_ascii == '-' || **from_ascii == '+')
	{
		if (**from_ascii == '-')
			sign *= NEGATIVE;
		*from_ascii += 1;
	}
	return (sign);
}

static int	check_flows(unsigned long long digit2p, \
	unsigned long long digit1, int sign)
{
	if (sign == POSITIVE)
	{
		if (digit2p > (unsigned long long)(LLONG_MAX / 10))
			return (ERROR);
		if (digit2p == (unsigned long long)(LLONG_MAX / 10) \
			&& digit1 > (unsigned long long)(LLONG_MAX % 10))
			return (ERROR);
	}
	else if (sign == NEGATIVE)
	{
		if (digit2p > (unsigned long long)(LLONG_MAX / 10))
			return (ERROR);
		if (digit2p == (unsigned long long)(LLONG_MAX / 10) \
			&& digit1 > (unsigned long long)(LLONG_MIN % 10))
			return (ERROR);
	}
	return (OK);
}

// int	main(void)
// {
// 	// printf("\n\t[null]\n");
// 	// printf("          +-0: %d\n", atoi(NULL));//segv
// 	// printf("          +-0: %d\n", ft_atoi(NULL));//segv
// 	printf("\n\t[sign space]\n");
// 	printf("            0: %ld\n", atol("0"));
// 	printf("            0: %ld\n", ft_atol("0"));
// 	printf("           +0: %ld\n", atol("+0"));
// 	printf("           +0: %ld\n", ft_atol("+0"));
// 	printf("           -0: %ld\n", atol("-0"));
// 	printf("           -0: %ld\n", ft_atol("-0"));
// 	printf("          -42: %ld\n", atol("-42"));
// 	printf("          -42: %ld\n", ft_atol("-42"));
// 	printf("          +-0: %ld\n", atol("+-0"));
// 	printf("          +-0: %ld\n", ft_atol("+-0"));
// 	printf("         +-42: %ld\n", atol("+-42"));
// 	printf("         +-42: %ld\n", ft_atol("+-42"));
// 	printf("      +---+42: %ld\n", atol("+---+42"));
// 	printf("      +---+42: %ld\n", ft_atol("+---+42"));
// 	printf("    +---+--42: %ld\n", atol("+---+--42"));
// 	printf("    +---+--42: %ld\n", ft_atol("+---+--42"));
// 	printf("   +---+---42: %ld\n", atol("+---+---42"));
// 	printf("   +---+---42: %ld\n", ft_atol("+---+---42"));
// 	printf("SP +---+---42: %ld\n", atol("     \n+---+---42"));
// 	printf("SP +---+---42: %ld\n", ft_atol("     \n+---+---42"));
// 	printf("SP  +---+--42: %ld\n", atol("     \n+---+--42"));
// 	printf("SP  +---+--42: %ld\n", ft_atol("     \n+---+--42"));
// 	printf("SP  +---+--42: %ld\n", atol("     \t\n\f\v\r+---+--42"));
// 	printf("SP  +---+--42: %ld\n", ft_atol("     \t\n\f\v\r+---+--42"));
// 	printf("SP        -42: %ld\n", atol("     \t\n\f\v\r-42"));
// 	printf("SP        -42: %ld\n", ft_atol("     \t\n\f\v\r-42"));
// 	printf("SP       --42: %ld\n", atol("     \t\n\f\v\r--42"));
// 	printf("SP       --42: %ld\n", ft_atol("     \t\n\f\v\r--42"));
// 	printf("SP      ---42: %ld\n", atol("     \t\n\f\v\r---42"));
// 	printf("SP      ---42: %ld\n", ft_atol("     \t\n\f\v\r---42"));
// 	printf("SP     ----42: %ld\n", atol("     \t\n\f\v\r----42"));
// 	printf("SP     ----42: %ld\n", ft_atol("     \t\n\f\v\r----42"));
// 	printf("SP    -----42: %ld\n", atol("     \t\n\f\v\r-----42"));
// 	printf("SP    -----42: %ld\n", ft_atol("     \t\n\f\v\r-----42"));
// 	printf("\n\t[IMAX IMIN]\n");
// 	printf(" 2147483647paper: %ld\n", atol(" 2147483647paper"));
// 	printf(" 2147483647paper: %ld\n", ft_atol(" 2147483647paper"));
// 	printf("      2147483650: %ld\n", atol(" 2147483650"));
// 	printf("      2147483650: %ld\n", ft_atol(" 2147483650"));
// 	printf("     32147483650: %ld\n", atol(" 32147483650"));
// 	printf("     32147483650: %ld\n", ft_atol(" 32147483650"));
// 	printf("-2147483648paper: %ld\n", atol(" -2147483648paper"));
// 	printf("-2147483648paper: %ld\n", ft_atol(" -2147483648paper"));
// 	printf("     -2147483650: %ld\n", atol(" -2147483650"));
// 	printf("     -2147483650: %ld\n", ft_atol(" -2147483650"));
// 	printf("   -322147483650: %ld\n", atol(" -322147483650"));
// 	printf("   -322147483650: %ld\n", ft_atol(" -322147483650"));
// 	printf("   -21474~=83650: %ld\n", atol(" -21474~=83650"));
// 	printf("   -21474~=83650: %ld\n", ft_atol(" -21474~=83650"));
// 	printf("  - 21474~=83650: %ld\n", atol(" - 21474~=83650"));
// 	printf("  - 21474~=83650: %ld\n", ft_atol(" - 21474~=83650"));
// 	printf("\n\t[LMAX LMIN]\n");
// 	printf("   lmax: %ld\n", LONG_MAX);
// 	printf("   lmin: %ld\n", LONG_MIN);
// 	// printf("(i)lmax: %ld\n", (int)LONG_MAX);
// 	// printf("(i)lmin: %ld\n", (int)LONG_MIN);
// 	printf("   lmax: %ld\n", atol(" 9223372036854775807"));
// 	printf("   lmax: %ld\n", ft_atol(" 9223372036854775807"));
// 	printf("   lmin: %ld\n", atol(" -9223372036854775808"));
// 	printf("   lmin: %ld\n", ft_atol(" -9223372036854775808"));
// 	printf(" lmax-1: %ld\n", atol(" 9223372036854775806"));
// 	printf(" lmax-1: %ld\n", ft_atol(" 9223372036854775806"));
// 	printf(" lmin+1: %ld\n", atol(" -9223372036854775807"));
// 	printf(" lmin+1: %ld\n", ft_atol(" -9223372036854775807"));
// 	printf(" lmax+3: %ld\n", atol(" 922337203685477580610"));
// 	printf(" lmax+3: %ld\n", ft_atol(" 9223372036854775810"));
// 	printf(" lmin-2: %ld\n", atol(" -9223372036854775810"));
// 	printf(" lmin-2: %ld\n", ft_atol(" -9223372036854775810"));
// 	return (0);
// }
