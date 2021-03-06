/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/rect.h"
#include "titanic/star_control/base_star.h"
#include "titanic/star_control/star_control_sub12.h"
#include "titanic/star_control/surface_area.h"

#ifndef TITANIC_STAR_REF_H
#define TITANIC_STAR_REF_H

namespace Titanic {

class CBaseStarRef {
protected:
	CBaseStar *_star;
public:
	CBaseStarRef(CBaseStar *star) : _star(star) {}
	CBaseStarRef() : _star(nullptr) {}
	virtual ~CBaseStarRef() {}

	void process(CSurfaceArea *surface, CStarControlSub12 *sub12);

	virtual bool check(const Common::Point &pt, int index) { return false; }
};

class CStarRef1 : public CBaseStarRef {
private:
	Common::Point _position;
public:
	int _index;
public:
	CStarRef1(CBaseStar *star, const Common::Point &pt) :
		CBaseStarRef(star), _index(-1) {}
	virtual ~CStarRef1() {}

	virtual bool check(const Common::Point &pt, int index);
};

class CStarRef2 : public CBaseStarRef {
private:
	Common::Array<CStarPosition> *_positions;
public:
	int _index;
public:
	CStarRef2(CBaseStar *star, Common::Array<CStarPosition> *positions) :
		CBaseStarRef(star), _positions(positions), _index(0) {}
	virtual ~CStarRef2() {}

	virtual bool check(const Common::Point &pt, int index);
};

class CStarRef3 : public CBaseStarRef {
public:
	int _index;
public:
	CStarRef3(CBaseStar *star) :CBaseStarRef(star), _index(0) {}
	virtual ~CStarRef3() {}

	virtual bool check(const Common::Point &pt, int index);
};

} // End of namespace Titanic

#endif /* TITANIC_STAR_REF_H */
