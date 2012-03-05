//The C driver file for a ROSS model
//This file includes:
// - initialized command line arguments
// - an initialization function
// - a forward event function
// - a reverse event function
// - a finalization function
// - all custom mapping functions (if needed)
// - the LP type definition 




/*
//Custom mapping fuctions are used to
// - no LPs are unused
// - event activity is balanced

extern unsigned int nkp_per_pe;
//#define VERIFY_MAPPING 1 //useful for debugging

//This function maps LPs to KPs on PEs and is called at the start
//This example is the same as Linear Mapping
void model_custom_mapping(void){
  tw_pe *pe;
  int nlp_per_kp;
  int lp_id, kp_id;
  int i, j;
  
  // nlp should be divisible by nkp (no wasted LPs)
  nlp_per_kp = ceil((double) g_tw_nlp / (double) g_tw_nkp);
  if (!nlp_per_kp) tw_error(TW_LOC, "Not enough KPs defined: %d", g_tw_nkp);
  
  //gid of first LP on this PE (aka node)
  g_tw_lp_offset = g_tw_my_node * g_tw_nlp;
  
#if VERIFY_MAPPING
  prinf("NODE %d: nlp %lld, offset %lld\n", g_tw_mynode, g_tw_nlp, g_tw_lp_offset);
#endif
  
  // Loop through each PE (node)
  for (kp_id = 0, lp_id = 0, pe = NULL; (pe = tw_pe_next(pe)); ) {
    
    // Define each KP on the PE
    for (i = 0; i < nkp_per_pe; i++, kp_id++) {
      
      tw_kp_onpe(kpid, pe);
      
      // Define each LP on the KP
      for (j = 0; j < nlp_per_kp && lp_id < g_tw_nlp; j++, lp_id++) {
	
	tw_lp_onpe(lp_id, pe, g_tw_lp_offset + lp_id);
	tw_lp_onkp(g_tw_lp[lp_id], g_tw_kp[kp_id]);
	
#if VERIFY_MAPPING
	if (0 == j % 20) { // print detailed output for only some LPs
	  printf("PE %d\tKP %d\tLP %d", pe->id, kp_id, (int) lp_id + g_tw_lp_offset);
	}
#endif
      }
    }
  }
  
  //Error checks for the mapping
  if (!g_tw_lp[g_tw_nlp - 1]) {
    tw_error(TW_LOC, "Not all LPs defined! (g_tw_nlp=%d)", g_tw_nlp);
  }
  
  if (g_tw_lp[g_tw_nlp - 1]->gid != g_tw_lp_offset + g_tw_nlp - 1) {
    tw_error(TW_LOC, "LPs not sequentially enumerated");
  }
}

//Given a gid, return the local LP (global id => local id mapping)
tw_lp * model_mapping_to_lp(tw_lpid){
  int local_id = lp_id - g_tw_offset;
  return g_tw_lp[id];
}

//Given a gid, return the PE (or node) id
tw_peid model_map(tw_lpid gid){
  return (tw_peid) gid / g_tw_nlp;
}
*/

//This defines the fuctions used by the LPs
//   multiple sets can be defined (for multiple LP types)
tw_lptype model_lps[] = {
  {
    (init_f) model_init,
    (event_f) model_event,
    (revent_f) model_event_reverse,
    (final_f) model_final,
    //(map_f) model_map,
    sizeof(model_state)
  },
  { 0 },
};
