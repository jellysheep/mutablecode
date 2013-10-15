/**
 * \file
 * \author jellysheep, ClundXIII, edlervonhuber.
 * \section LICENSE
 * Copyright (c) 2013, jellysheep, ClundXIII, edlervonhuber.
 * All rights reserved.
 * This file is licensed under the "BSD 3-Clause License".
 * Full license text is under the file "LICENSE" provided with this code.
 */

#ifndef _TAPE_HPP_
#define _TAPE_HPP_

#include <list>
#include <iostream>
#include <algorithm>

#include <Operation.hpp>

namespace MutableCode
{

	typedef std::list<char> CharList;
	const char defaultTapeValue = BasicCharset[0];
	
	class Tape
	{
	private:
		CharList data;
		CharList::iterator current;
		
	public:
		Tape()
		{
			data.push_front(defaultTapeValue);
			current = data.begin();
		}
		
		inline void moveRight()
		{
			if(current != --data.end())
				current++;
			else
			{
				data.push_back(defaultTapeValue);
				current = --data.end();
			}
		}
		
		inline void moveLeft()
		{
			if(current != data.begin())
				current--;
			else
			{
				data.push_front(defaultTapeValue);
				current = data.begin();
			}
		}
		
		inline void write(const char c)
		{
			*current = c;
		}
		
		inline char read() const
		{
			return *current;
		}
		
		inline void clear()
		{
			data.clear();
			data.push_front(defaultTapeValue);
			current = data.begin();
		}
		
		friend std::ostream& operator<<(std::ostream& s, const Tape& t)
		{
			s<<"<Tape:";
			for(CharList::const_iterator it = t.data.begin(); it!=t.data.end(); it++)
			{
				s<<" ";
				if(it == t.current)
					s<<"*";
				s<<(int)*it;
				if(it == t.current)
					s<<"*";
			}
			s<<">";
			return s;
		}
		
		friend std::istream& operator>>(std::istream& s, Tape& t)
		{
			int c;
			s>>c;
			t.write((char)c);
			
			return s;
		}
	};

}

#endif
