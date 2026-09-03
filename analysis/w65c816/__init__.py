"""Offline W65C816 semantic-analysis foundation for V02C.

This package is analysis/test authority only.  It is not a production runtime
interpreter and must not be linked into the eventual static target.
"""

from .opcodes import OPCODES, OpcodeSpec, iter_raw_contexts
from .semantics import CPUState, SemanticEngine

__all__ = ["OPCODES", "OpcodeSpec", "iter_raw_contexts", "CPUState", "SemanticEngine"]

from .decode import DecodedContext, DecodeContextError, decode_context
