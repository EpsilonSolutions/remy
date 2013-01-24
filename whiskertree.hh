#ifndef WHISKERTREE_HH
#define WHISKERTREE_HH

#include "whisker.hh"
#include "memoryrange.hh"
#include "dna.pb.h"

class WhiskerTree {
private:
  MemoryRange _domain;

  std::vector< WhiskerTree > _children;
  std::vector< Whisker > _leaf;

  const Whisker * whisker( const Memory & _memory ) const;

public:
  WhiskerTree();

  WhiskerTree( const Whisker & whisker, const bool bisect );

  const Whisker & use_whisker( const Memory & _memory, const bool track ) const;

  bool replace( const Whisker & w );
  bool replace( const Whisker & src, const WhiskerTree & dst );
  const Whisker * most_used( const unsigned int max_generation ) const;

  void reset_counts( void );
  void promote( const unsigned int generation );

  std::string str( void ) const;

  unsigned int num_children( void ) const;

  bool is_leaf( void ) const;

  RemyBuffers::WhiskerTree DNA( void ) const;
};

#endif
