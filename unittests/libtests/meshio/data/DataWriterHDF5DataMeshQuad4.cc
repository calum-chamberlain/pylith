// -*- C++ -*-
//
// ======================================================================
//
// Brad T. Aagaard, U.S. Geological Survey
// Charles A. Williams, GNS Science
// Matthew G. Knepley, University of Chicago
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010-2015 University of California, Davis
//
// See COPYING for license information.
//
// ======================================================================
//

#include "DataWriterHDF5DataMeshQuad4.hh"

#include <assert.h> // USES assert()

const char* pylith::meshio::DataWriterHDF5DataMeshQuad4::_meshFilename = 
  "data/quad4.mesh";

const char* pylith::meshio::DataWriterHDF5DataMeshQuad4::_timestepFilename = 
  "quad4.h5";

const char* pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFilename = 
  "quad4_vertex.h5";

const char* pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFilename = 
  "quad4_cell.h5";

const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_time = 1.0;

const char* pylith::meshio::DataWriterHDF5DataMeshQuad4::_timeFormat = 
  "%3.1f";

const int pylith::meshio::DataWriterHDF5DataMeshQuad4::_numVertices = 6;

const pylith::meshio::DataWriterData::FieldStruct
pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFields[4] = {
  { "pressure", topology::FieldBase::SCALAR, 1 },
  { "displacement", topology::FieldBase::VECTOR, 2 },
  { "stress", topology::FieldBase::TENSOR, 3 },
  { "other", topology::FieldBase::OTHER, 2 },
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFieldScalar[6*1] = {
  2.1, 3.2, 4.3, 5.4, 6.5, 7.6
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFieldVector[6*2] = {
  1.1, 2.2,
  3.3, 4.4,
  5.5, 6.6,
  7.7, 8.8,
  9.9, 10.1,
  11.2, 12.3,
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFieldTensor[6*3] = {
  1.1, 1.2, 1.3,
  2.1, 2.2, 3.3,
  3.1, 3.2, 4.3,
  4.1, 4.2, 5.3,
  5.1, 5.2, 6.3,
  6.1, 6.2, 7.3,
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_vertexFieldOther[6*2] = {
  1.2, 2.3,
  3.4, 4.5,
  5.6, 6.7,
  7.8, 8.9,
  9.8, 7.6,
  6.5, 5.4
};

const int pylith::meshio::DataWriterHDF5DataMeshQuad4::_numCells = 2;

const pylith::meshio::DataWriterData::FieldStruct
pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFields[4] = {
  { "pressure", topology::FieldBase::SCALAR, 1 },
  { "traction", topology::FieldBase::VECTOR, 2 },
  { "stress", topology::FieldBase::TENSOR, 3 },
  { "other", topology::FieldBase::OTHER, 2 },
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFieldScalar[2*1] = {
  2.1, 2.2,
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFieldVector[2*2] = {
  1.1, 2.2,
  3.3, 4.4
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFieldTensor[2*3] = {
  1.2, 2.3, 3.4,
  4.5, 5.6, 6.7,
};
const PylithScalar pylith::meshio::DataWriterHDF5DataMeshQuad4::_cellFieldOther[2*2] = {
  1.2, 2.3,
  4.5, 5.6,
};

pylith::meshio::DataWriterHDF5DataMeshQuad4::DataWriterHDF5DataMeshQuad4(void)
{ // constructor
  meshFilename = const_cast<char*>(_meshFilename);

  timestepFilename = const_cast<char*>(_timestepFilename);
  vertexFilename = const_cast<char*>(_vertexFilename);
  cellFilename = const_cast<char*>(_cellFilename);

  time = _time;
  timeFormat = const_cast<char*>(_timeFormat);
  
  numVertices = _numVertices;
  assert(DataWriterData::numVertexFields == numVertexFields);
  vertexFieldsInfo = const_cast<DataWriterData::FieldStruct*>(_vertexFields);
  vertexFields[0] = const_cast<PylithScalar*>(_vertexFieldScalar);
  vertexFields[1] = const_cast<PylithScalar*>(_vertexFieldVector);
  vertexFields[2] = const_cast<PylithScalar*>(_vertexFieldTensor);
  vertexFields[3] = const_cast<PylithScalar*>(_vertexFieldOther);

  numCells = _numCells;
  assert(DataWriterData::numCellFields == numCellFields);
  cellFieldsInfo = const_cast<DataWriterData::FieldStruct*>(_cellFields);
  cellFields[0] = const_cast<PylithScalar*>(_cellFieldScalar);
  cellFields[1] = const_cast<PylithScalar*>(_cellFieldVector);
  cellFields[2] = const_cast<PylithScalar*>(_cellFieldTensor);
  cellFields[3] = const_cast<PylithScalar*>(_cellFieldOther);
} // constructor

pylith::meshio::DataWriterHDF5DataMeshQuad4::~DataWriterHDF5DataMeshQuad4(void)
{}


// End of file
