/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "suma_ff_impl.h"

namespace gr {
  namespace howto {

    suma_ff::sptr
    suma_ff::make()
    {
      return gnuradio::get_initial_sptr
        (new suma_ff_impl());
    }

    /*
     * The private constructor
     */
    suma_ff_impl::suma_ff_impl()
      : gr::block("suma_ff",
              gr::io_signature::make(2, 2, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {}

    /*
     * Our virtual destructor.
     */
    suma_ff_impl::~suma_ff_impl()
    {
    }

    void
    suma_ff_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
      ninput_items_required[1] = noutput_items;
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    /* Comienza la funcion general_work donde se hace el procesamiento*/
    /* se define como int, pues devolvera noutput_items*/

    int
    suma_ff_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in0 = (const float *) input_items[0];   // llamado "casteo de buffers"
      const float *in1 = (const float *) input_items[1];
      float *out = (float *) output_items[0];

      for(int i = 0; i < noutput_items; i++)
      {
        out[i] = in0[i] + in1[i];
      }
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace howto */
} /* namespace gr */

