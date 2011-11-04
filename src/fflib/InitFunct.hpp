// -*- Mode : c++ -*-
//
// SUMMARY  :      
// USAGE    :        
// ORG      : 
// AUTHOR   : Frederic Hecht
// E-MAIL   : hecht@ann.jussieu.fr
//

/*
 
 This file is part of Freefem++
 
 Freefem++ is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 Freefem++  is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with Freefem++; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef INITSFUNCT_HPP_
#define INITSFUNCT_HPP_

void  addInitFunct(int i,void  (* f)(),const char *name) ;
void  callInitsFunct() ;
struct  addingInitFunct { 
  addingInitFunct(int i,void  (* f)(),const char *name=0) { addInitFunct(i,f,name);}
} ;

template<class TI> void  AutoLoadInit() { static TI init; }
//
  
#define LOADINIT(TI) static addingInitFunct  loadinit(1000,AutoLoadInit<TI>,__FILE__) ; 


#endif
