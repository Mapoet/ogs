/**
 * @copyright
 * Copyright (c) 2012-2014, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/LICENSE.txt
 */
#ifndef BOUNDARYELEMENTSALONGSURFACE_H_
#define BOUNDARYELEMENTSALONGSURFACE_H_

#include <vector>

namespace GeoLib
{
class Surface;
}

namespace MeshLib
{
class Mesh;
class Element;
}

namespace MeshGeoToolsLib
{
class MeshNodeSearcher;

/**
 * This class collects element faces located along a surface.
 * Note that internal faces are not collected in this class.
 */
class BoundaryElementsAlongSurface
{
public:
	/**
	 * Constructor
	 * @param mesh             a mesh object
	 * @param mshNodeSearcher  a MeshNodeSearcher object which is internally used to search mesh nodes
	 * @param sfc              a surface object where face elements are searched for
	 */
	BoundaryElementsAlongSurface(MeshLib::Mesh const& mesh, MeshNodeSearcher &mshNodeSearcher, GeoLib::Surface const& sfc);

	/// destructor
	virtual ~BoundaryElementsAlongSurface();

	/// return the mesh object
	MeshLib::Mesh const& getMesh() const {return _mesh;}

	/**
	 * Deploying this method the user can get access to the underlying
	 * GeoLib::Surface.
	 * @return the underlying GeoLib::Surface
	 */
	GeoLib::Surface const& getSurface() const {return _sfc;}

	/**
	 * Return the vector of boundary elements
	 */
	std::vector<MeshLib::Element*> const& getBoundaryElements() const {return _boundary_elements;}

private:
	MeshLib::Mesh const& _mesh;
	GeoLib::Surface const& _sfc;
	std::vector<MeshLib::Element*> _boundary_elements;
};

} // end namespace MeshGeoTools

#endif /* BOUNDARYELEMENTSALONGSURFACE_H_ */
