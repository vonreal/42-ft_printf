///* [width][.N] */
ft_printf("[%10s]1\n", "abc");	//	[         a]
printf("[%10s]\n", "abc");	//	[         a]
ft_printf("[%10.11s]2\n", "abc");	//	[         a]
printf("[%10.11s]\n", "abc");	//	[         a]
ft_printf("[%.10s]3\n", "abc");	//	[         a]
printf("[%.10s]\n", "abc");	//	[         a]
ft_printf("[%.3s]4\n", "abc");	//	[         a]
printf("[%.3s]\n", "abc");	//	[         a]
ft_printf("[%.1s]5\n", "abc");	//	[         a]
printf("[%.1s]\n", "abc");	//	[         a]
ft_printf("[%1.0s]6\n", "abc");	//	[         a]
printf("[%1.0s]\n", "abc");	//	[         a]
ft_printf("[%.10s]7\n", "a");	//	[         a]
printf("[%.10s]\n", "a");	//	[         a]
///* [][.N] */
ft_printf("[%.2s]8\n", "a");		//	[a] 
printf("[%.2s]\n", "a");		//	[a] 
ft_printf("[%.2s]\n", "abc");	//	[ab]
printf("[%.2s]\n", "abc");	//	[ab]
//
///* [-][.N] */
ft_printf("[%-.2s]9\n", "a");		//	[a] 
printf("[%-.2s]\n", "a");		//	[a] 
ft_printf("[%-.2s]10\n", "abc");	//	[ab]
printf("[%-.2s]\n", "abc");	//	[ab]
//
///* [width][.N] */
ft_printf("[%10.2s]11\n", "a");	//	[         a]
printf("[%10.2s]\n", "a");	//	[         a]
ft_printf("[%5.2s]12\n", "abc");	//	[   ab]
printf("[%5.2s]\n", "abc");	//	[   ab]


///* [-][width][.N] */
ft_printf("[%-10.2s]13\n", "a");	//	[a         ]
printf("[%-10.2s]\n", "a");	//	[a         ]
ft_printf("[%-5.2s]14\n", "abc");	//	[ab   ]
printf("[%-5.2s]\n", "abc");	//	[ab   ]


////////////////////////////////////////////

///* [][.0] */
ft_printf("[%.0s]15\n", "a");		//	[] 
printf("[%.0s]\n", "a");		//	[] 
ft_printf("[%.0s]16\n", "abc");	//	[]
printf("[%.0s]\n", "abc");	//	[]
//
///* [-][.0] */
ft_printf("[%-.0s]17\n", "a");		//	[] 
printf("[%-.0s]\n", "a");		//	[] 
ft_printf("[%-.0s]18\n", "abc");	//	[]
printf("[%-.0s]\n", "abc");	//	[]
//
///* [width][.0] */
ft_printf("[%10.0s]19\n", "a");	//	[          ]
printf("[%10.0s]\n", "a");	//	[          ]
ft_printf("[%5.0s]20\n", "abc");	//	[     ]
printf("[%5.0s]\n", "abc");	//	[     ]
//
///* [-][width][.0] */
ft_printf("[%-10.0s]21\n", "a");	//	[          ]
printf("[%-10.0s]\n", "a");	//	[          ]
ft_printf("[%-5.0s]22\n", "abc");	//	[     ]
printf("[%-5.0s]\n", "abc");	//	[     ]


////////////////////////////////////////////

/* [][.*] 양수 == [][.N] */

////////////////////////////////////////////

///* [][.*] 음수 */
ft_printf("[%.*s]23\n", -2, "a");	//	[a] 
printf("[%.*s]\n", -2, "a");	//	[a] 
ft_printf("[%.*s]24\n", -2, "abc");	//	[abc]
printf("[%.*s]\n", -2, "abc");	//	[abc]
//
///* [-][.*] 음수 */
ft_printf("[%-.*s]25\n", -2, "a");	//	[a] 
printf("[%-.*s]\n", -2, "a");	//	[a] 
ft_printf("[%-.*s]26\n", -2, "abc");	//	[abc]
printf("[%-.*s]\n", -2, "abc");	//	[abc]
//
///* [width][.*] 음수 */
ft_printf("[%10.*s]27\n", -2, "a");	//	[         a]
printf("[%10.*s]\n", -2, "a");	//	[         a]
ft_printf("[%5.*s]28\n", -2, "abc");	//	[  abc]
printf("[%5.*s]\n", -2, "abc");	//	[  abc]
//
//
///* [-][width][.*] 음수 */
ft_printf("[%-10.*s]29\n", -2, "a");	//	[a         ]
printf("[%-10.*s]\n", -2, "a");	//	[a         ]
ft_printf("[%-5.*s]30\n", -2, "abc");	//	[abc  ]
printf("[%-5.*s]\n", -2, "abc");	//	[abc  ]