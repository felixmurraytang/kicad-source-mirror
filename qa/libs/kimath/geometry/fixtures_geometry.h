/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2017 CERN
 * @author Alejandro García Montoro <alejandro.garciamontoro@gmail.com>
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
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef QA_COMMON_GEOMETRY_FIXTURES_GEOEMETRY__H
#define QA_COMMON_GEOMETRY_FIXTURES_GEOEMETRY__H

#include <geometry/shape_line_chain.h>
#include <geometry/shape_poly_set.h>

namespace KI_TEST
{

/**
 * Common data for some of the #SHAPE_POLY_SET tests:
 *      1. holeyPolySet: A polyset containing one single squared outline with two holes: a
 *      non-convex pentagon and a triangle.
 *      2.solidPolySet: A polyset with three empty outlines and no holes.
 *      3. uniqueVertexPolySet: A polyset with one single outline that contains just one vertex.
 *      4. emptyPolySet: A polyset with no outlines.
 */
struct CommonTestData
{
    // Polygon sets common for all the tests
    SHAPE_POLY_SET emptyPolySet;
    SHAPE_POLY_SET uniqueVertexPolySet;
    SHAPE_POLY_SET solidPolySet;
    SHAPE_POLY_SET holeyPolySet;
    SHAPE_POLY_SET holeyCurvedPolySingle; ///< Polygon with a single outline + multiple holes.
                                          ///< Holes and outline contain arcs
    SHAPE_POLY_SET holeyCurvedPolyMulti;  ///< Polygon with a multiple outlines + multiple holes.
                                          ///< Holes and outlines contain arcs

    // Vectors containing the information with which the polygons are populated.
    std::vector<VECTOR2I> uniquePoints;
    std::vector<VECTOR2I> holeyPoints;
    std::vector<SEG>      holeySegments;

    /**
     * Constructor.
     */
    CommonTestData()
    {
        // UniqueVertexPolySet shall have a unique vertex
        uniquePoints.emplace_back( 100, 50 );

        // Populate the holey polygon set points with 12 points

        // Square
        holeyPoints.emplace_back( 100, 100 );
        holeyPoints.emplace_back( 0, 100 );
        holeyPoints.emplace_back( 0, 0 );
        holeyPoints.emplace_back( 100, 0 );

        // Pentagon
        holeyPoints.emplace_back( 10, 10 );
        holeyPoints.emplace_back( 10, 20 );
        holeyPoints.emplace_back( 15, 15 );
        holeyPoints.emplace_back( 20, 20 );
        holeyPoints.emplace_back( 20, 10 );

        // Triangle
        holeyPoints.emplace_back( 40, 10 );
        holeyPoints.emplace_back( 40, 20 );
        holeyPoints.emplace_back( 60, 10 );

        // Save the segments of the holeyPolySet.
        holeySegments.emplace_back( holeyPoints[0], holeyPoints[1] );
        holeySegments.emplace_back( holeyPoints[1], holeyPoints[2] );
        holeySegments.emplace_back( holeyPoints[2], holeyPoints[3] );
        holeySegments.emplace_back( holeyPoints[3], holeyPoints[0] );

        // Pentagon segments
        holeySegments.emplace_back( holeyPoints[4], holeyPoints[5] );
        holeySegments.emplace_back( holeyPoints[5], holeyPoints[6] );
        holeySegments.emplace_back( holeyPoints[6], holeyPoints[7] );
        holeySegments.emplace_back( holeyPoints[7], holeyPoints[8] );
        holeySegments.emplace_back( holeyPoints[8], holeyPoints[4] );

        // Triangle segments
        holeySegments.emplace_back( holeyPoints[9], holeyPoints[10] );
        holeySegments.emplace_back( holeyPoints[10], holeyPoints[11] );
        holeySegments.emplace_back( holeyPoints[11], holeyPoints[9] );

        // Auxiliary variables to store the contours that will be added to the polygons
        SHAPE_LINE_CHAIN polyLine, hole;

        // Create a polygon set with a unique vertex
        polyLine.Append( uniquePoints[0] );
        polyLine.SetClosed( true );
        uniqueVertexPolySet.AddOutline( polyLine );

        // Create a polygon set without holes
        solidPolySet.NewOutline();
        solidPolySet.NewOutline();
        solidPolySet.NewOutline();

        // Create a polygon set with holes

        // Adds a new squared outline
        polyLine.Clear();

        for( int i = 0; i < 4; i++ )
            polyLine.Append( holeyPoints[i] );

        polyLine.SetClosed( true );

        holeyPolySet.AddOutline( polyLine );

        // Adds a new hole (a pentagon)
        for( int i = 4; i < 9; i++ )
            hole.Append( holeyPoints[i] );

        hole.SetClosed( true );
        holeyPolySet.AddHole( hole );


        // Adds a new hole (a triangle)
        hole.Clear();
        for( int i = 9; i < 12; i++ )
            hole.Append( holeyPoints[i] );

        hole.SetClosed( true );
        holeyPolySet.AddHole( hole );


        // GENERATE CURVED POLYGON WITH HOLES
        // For visualisation, launch test_pns with the arguments "viewcurvedpoly -[single|multi]"

        // First shape:
        SHAPE_LINE_CHAIN oline0;
        oline0.Append( { 244000, 180000 } );
        oline0.Append( SHAPE_ARC( { 582000, 232000 }, { 614000, 354000 }, { 450000, 436000 }, 0 ) );
        oline0.Append( SHAPE_ARC( { 450000, 436000 }, { 310000, 480000 }, { 502000, 614000 }, 0 ) );
        oline0.Append( { 872000, 202000 } );
        oline0.SetClosed( true );
        holeyCurvedPolySingle.AddOutline( oline0 );

        SHAPE_LINE_CHAIN o0h1;
        o0h1.Append( { 370000, 482000 } );
        o0h1.Append( SHAPE_ARC( { 342000, 576000 }, { 436000, 552000 }, { 474000, 622000 }, 0 ) );
        o0h1.Append( SHAPE_ARC( { 474000, 622000 }, { 534000, 520000 }, { 518000, 470000 }, 0 ) );
        o0h1.SetClosed( true );
        holeyCurvedPolySingle.AddHole( o0h1 );

        SHAPE_LINE_CHAIN o0h2;
        o0h2.Append( SHAPE_ARC( { 680000, 286000 }, { 728000, 306000 }, { 760000, 258000 }, 0 ) );
        o0h2.Append( SHAPE_ARC( { 760000, 258000 }, { 746000, 222000 }, { 686000, 260000 }, 0 ) );
        o0h2.SetClosed( true );
        holeyCurvedPolySingle.AddHole( o0h2 );

        holeyCurvedPolyMulti = holeyCurvedPolySingle;

        // Second shape:
        SHAPE_LINE_CHAIN oline1;
        oline1.Append( { 640000, 840000 } );
        oline1.Append( SHAPE_ARC( { 829000, 959000 }, { 990000, 736000 }, { 951000, 461000 }, 0 ) );
        oline1.Append( SHAPE_ARC( { 951000, 461000 }, { 600000, 572000 }, { 620000, 726000 }, 0 ) );
        oline1.SetClosed( true );
        holeyCurvedPolyMulti.AddOutline( oline1 );

        SHAPE_LINE_CHAIN o1h1;
        o1h1.Append( { 670000, 482000 } );
        o1h1.Append( SHAPE_ARC( { 642000, 576000 }, { 736000, 652000 }, { 774000, 622000 }, 0 ) );
        o1h1.Append( SHAPE_ARC( { 774000, 622000 }, { 834000, 520000 }, { 818000, 470000 }, 0 ) );
        o1h1.SetClosed( true );
        holeyCurvedPolyMulti.AddHole( o1h1 );

        SHAPE_LINE_CHAIN o1h2;
        o1h2.Append( SHAPE_ARC( { 680000, 286000 }, { 728000, 306000 }, { 760000, 258000 }, 0 ) );
        o1h2.Append( SHAPE_ARC( { 760000, 258000 }, { 746000, 222000 }, { 686000, 260000 }, 0 ) );
        o1h2.SetClosed( true );
        holeyCurvedPolyMulti.AddHole( o1h2 );
    }

    ~CommonTestData()
    {
    }
};

} // namespace KI_TEST

#endif // QA_COMMON_GEOMETRY_FIXTURES_GEOEMETRY__H
