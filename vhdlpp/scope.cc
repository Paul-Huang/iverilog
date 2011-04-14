/*
 * Copyright (c) 2011 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

# include  "scope.h"

using namespace std;

Scope::Scope(map<perm_string,ComponentBase*>&comps)
{
      components_ = comps;
}

Scope::~Scope()
{
}

ComponentBase* Scope::find_component(perm_string by_name)
{
      map<perm_string,ComponentBase*>::const_iterator cur = components_.find(by_name);
      if (cur == components_.end())
	    return 0;
      else
	    return cur->second;
}

void Scope::collect_components(list<ComponentBase*>&res)
{
      for (map<perm_string,ComponentBase*>::const_iterator cur = components_.begin()
		 ; cur != components_.end() ; ++cur) {
	    if (cur->second == 0)
		  continue;
	    res.push_back(cur->second);
      }
}
